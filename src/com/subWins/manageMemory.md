# Memory Enhancement #

### 检测方法 ###
1. 通过monkey压力测试记录内存的使用情况，分析数据曲线图和日志情况；
2. 通过eclipse上的MAT + Heap来分析存在内存泄漏方面的节点;

### Android内存限制 ###
adb pull /system/build.prop   导出build文件，文件中有相关的阈值。
1、dalvik.vm.heapgrowthlimit   单个应用程序最大内存限制，超过这个值会产生OOM
2、dalvik.vm.heapsize          单个JAVA虚拟机最大的内存限制，超过这个值会产生OOM
3、dalvik.vm.heapstartsize     应用程序启动后分配的初始内存，调节这个值会影响到应用的流畅性和整体RAM消耗。这个值越小，系统RAM消耗越慢；相反，这个值越大系统RAM消耗越快，但是程序更流畅。

### How to get memory data？ ###
    adb shell dumpsys meminfo -a $packagename/$pid
	eg: adb shell dumpsys meminfo -a com.android.photos

### OOM common causes？ ###
1. 非静态内部类的静态实例容易造成内存泄漏；
2. activity使用静态成员；
3. 使用handle时的内存问题；
4. 注册某个对象后未反注册；
5. 集合中对象没清理造成的内存泄漏；
6. 资源对象没关闭造成的内存泄漏；
7. 一些不良代码造成内存压力：Bitmap使用不当；构造Adapter时，没有使用缓存convertView；在经常调用的方法中创建对象（例如循环）。
