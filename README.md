# PngPacker
## 1.简介

PngPacker是libpacker的一种实现，它基于Qt的API接口实现了libpacker中的ImageReader和ImageWriter，并提供了一个简略的UI界面供用户打包和解包图片。



## 2.注意事项

* 不支持中文路径

由于libpacker未使用宽字符，因此PngPacker中输入的路径不应该出现中文字符，换句话说，libpacker和PngPacker暂不支持中文路径。

* 需要编译libpacker库

由于平台可能不同，PngPacker的源码中没有自带libpacker库，因此从源码编译的用户需要先下载libpacker的源码并编译出静态库**libpacker.a**，然后将它移动到PngPacker的项目根目录后再编译。
