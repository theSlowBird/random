# 更新日志`Change Log`

## [1.0.0] - 2022.10.27

### 优化`Refactored`

* 主词条的bp更改为与`character`或其子类绑定

### 修复`Fixed`

* 修复了魔导绪论`Magic Guide`增伤区错误的问题，现在正常加成`0.24`

## [1.0.1] - 2022.10.28

### 优化`Refactored`
```cpp
typename = enable_if_t<is_base_of<character, T>::value>
```

## [1.1.0] - 2022.11.1

### 新增`Features`

* 新增了跨装备比较功能，可以清楚看到不同装备间的差异以及装备对圣遗物刷取难度的影响

## [1.1.1] - 2022.11.2

### 修复`Fixed`

* 修复了纳西妲的天赋暴率不能正常结算的问题

## [1.2.0] - 2022.11.14

### 新增`Features`

* 新增了纳西妲开q
* 部分武器特效可以指定层数

### 修复`Fixed`

* 修复了纳西妲突破精通异常（155->115.2）

## [1.2.1] - 2023.4.2

### 修复`Fixed`
* 文件名中的尖括号自动合法化，并将输出全部放入data文件夹

### 新增`Features`
* plot>100

## [1.3.0] - 2023.11.19

### 优化`Refactored`
```cpp
template<typename T>
concept derived_from_character = derived_from<T, character>;
```