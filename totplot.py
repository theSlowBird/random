import csv
import os
import re

import numpy as np
from matplotlib import pyplot as plt
from matplotlib.ticker import MultipleLocator, AutoMinorLocator

plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']


def paint(intro_, mean_, std_, ref):
    fig1, ax1 = plt.subplots()
    ax2 = ax1.twinx()
    ax1.grid()
    ax1.set_xlabel('betterer时间/月')
    ax1.set_ylabel(r'目标函数/平均值$\pm$标准差(68.27%)')
    ax1.set_title(intro_)
    ax1.plot(np.arange(mean_.size) + 1, mean_)
    # ax1.plot(np.arange(mean_.size) + 1, mean_)
    ax1.fill_between(np.arange(mean_.size) + 1, mean_ - std_, mean_ + std_, alpha=0.3)
    ax2.fill_between(np.arange(mean_.size) + 1, mean_ - std_, mean_ + std_, alpha=0)

    ax1.xaxis.set_minor_locator(MultipleLocator(base=1))
    ax1.yaxis.set_minor_locator(AutoMinorLocator())
    plt.grid(which='minor', linestyle=':', linewidth=0.5)
    # plt.grid(which='major', linestyle='-', linewidth=1)
    # plt.show()

    print('ylim', mean_[0] - std_[0], mean_[-1] + std_[-1])
    start = int(np.log10((mean_[0] - std_[0]) / ref) * 100)
    end = int(np.log10((mean_[-1] + std_[-1]) / ref) * 100) + 1
    print('range', start, end)
    ticks = np.arange(start, end + 1)
    labels = [f'{tick}ddB' for tick in ticks]
    vals = 10 ** (ticks / 100) * ref

    ax1.set_ylim(vals[0], vals[-1])
    ax2.set_ylim(vals[0], vals[-1])

    # 设置新纵轴的刻度位置和标签
    ax2.set_yticks(vals)
    ax2.set_yticklabels(labels)

    filename = re.compile(r'[<>:"/\\|?*]').sub('_', intro_)
    print(f'{filename = }')
    if not os.path.exists('pic'):
        os.mkdir('pic')
    fig1.savefig(os.path.join('pic', filename + '.png'), dpi=400)


def main():
    file = 'data/class Hu_Tao,MONTH=12,PERSONS=1000.csv'
    for file in os.listdir('data'):
        if int(re.compile(r'(?<=PERSONS=)(\d+)').search(file).group()) <= 100:
            continue
        print(file)
        paint_from_file(os.path.join('data', file))
    # paint_from_file(file)


def paint_from_file(file):
    with open(file, 'r', encoding='utf-8') as csvfile:
        csvreader = csv.reader(csvfile)
        # 跳过第一行
        next(csvreader)
        # 读取剩下的行
        rows = [row for row in csvreader]  # 去除最后一行
        if not re.compile(r'\d').match(rows[-1][0]):
            return
        ref = float(rows[-1][0])
        intro = ','.join(rows[-1][1:])
        if re.compile(r'\d').match(intro):
            return
        # 将 Python 列表转换为 NumPy 数组
        data = np.array(rows[:-1])
        print(f'{intro = }')
        # print(data)
        mean_ = np.array(data[..., 1], dtype=np.float_)
        print(f'{mean_ = }')
        std_ = np.array(data[..., 2], dtype=np.float_)
        print(f'{std_ = }')
        paint(intro, mean_, std_, ref)
        # print(np.genfromtxt(BytesIO(bytes(std[0], encoding='utf-8'))))


if __name__ == '__main__':
    main()
