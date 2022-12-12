# 更新日志

## [6.2.4] - 2015-12-16

### 变更

* `Node.fn.map()` 之前返回 NodeList 自身，现在将正确地返回被 map 后的数组。

### 修复

* 修复在非 ks-debug 模式下仍然输出 `KISSY.log()` 控制台信息的问题。

## [6.2.3] - 2015-11-16

### 修复

* 修复 `KISSY.getScript` 在传入了 `timeout` 参数后报错的问题。[#12]

## [6.2.2] - 2015-11-04

### 新增

* node 模块增加 API `Node.fn`，以兼容传统 KIMI 的 node 对象扩展机制。 
* ua 模块现在可以识别 Microsoft Edge 浏览器。

### 优化

* `KISSY.getScript()` 从 loader 模块中独立出来，io 模块不再依赖 loader 模块。

### 已删除

* io 模块默认去掉了对 XML 的 converter 支持。


```新增（Features）：新增功能。
修复（Fixed）：修复 bug。
变更（Changed）：对于某些已存在功能所发生的逻辑变化。
优化（Refactored）：性能或结构上的优化，并未带来功能的逻辑变化。
即将删除（Deprecated）：不建议使用 / 在以后的版本中即将删除的功能。
删除（Removed）：已删除的功能。
```
