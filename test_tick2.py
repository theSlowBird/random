import numpy as np
import matplotlib.pyplot as plt

# 生成数据
x = np.linspace(0, 10, 100)
y = np.exp(x)

# 绘制图形
fig, ax1 = plt.subplots()
ax1.plot(x, y, label='y')

# 创建新的纵轴
ax2 = ax1.twinx()
ax2.set_yscale('log')

# 计算刻度位置和标签
print(ax1.get_ylim())
start = np.log10(ax1.get_ylim()[0])
end = np.log10(ax1.get_ylim()[1])
print(start, end)
ticks = np.arange(start, end + 0.01, 0.01)
labels = ['{}ddB'.format(tick*100) for tick in ticks]

# 设置新纵轴的刻度位置和标签
ax2.set_yticks(10**ticks)
ax2.set_yticklabels(labels)

plt.show()
