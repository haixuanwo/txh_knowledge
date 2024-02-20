
# vscode

官网
https://code.visualstudio.com/

## 1、插件
C/C++

GitHub：GitHub

画思维导图：vscode-mindmap，打开：ctrl+m

UML：PlantUML，预览alt+D
@startuml FirstUML
Interface Interface01

Interface01 <|.. Class01 : 实现
class02 <|-- Class03     : 继承
Class04 *-- Class05      : 组合
Class06 o-- Class07      : 聚合
Class08 <-- Class9       : 关联
Class10 <.. Class11      : 依赖

@enduml


## 2、快捷键
Ctrl + F12跳到函数的实现处
Ctrl + g跳到某行
Ctrl + p打开指定的文件
Shift + F12跳到函数引用处F2光标放到函数或者变量名上，然后按下F2。会修改所有出现的地方
CTRL + L 选择整行
ctrl+/当行注释，再按一次取消
ctrl+shift+a注释鼠标选中的多行
alt+up/down移动行
ctrl + b显示/隐藏左侧目录栏
shift + alt +up/down复制当前行
shift + ctrl + k删除当前行
ctrl + [行增加缩进ctrl + ]行减少缩进
ctrl + home快速回到顶部
ctrl + end快速回到底部
