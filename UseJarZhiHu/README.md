# How to use Jar
https://zhuanlan.zhihu.com/p/82320492

## compile
```
////In same package: one class call another class
//cd UseJarZhiHu\jardemo1\src
javac com/imooc/jardemo1/Welcome.java

//no main manifest attribute, in welcome.jar	//MANIFEST.MF
jar -cvfm welcome.jar META-INF/MANIFEST.MF com/imooc/jardemo1/Welcome.class com/imooc/jardemo1/impl/Teacher.class
java -jar welcome.jar

////避免每次打jar的时候都要指定所有class文件
//cd UseJarZhiHu\jardemo1\src
javac com/imooc/jardemo1/Welcome.java      -d target
//!!!! //if "-d target", should add "other class"
javac com/imooc/jardemo1/impl/Teacher.java -d target
cd target
md META-INF
copy ..\META-INF\MANIFEST.MF  .\META-INF\
jar -cvfm welcome.jar META-INF/MANIFEST.MF *

java -jar welcome.jar
java -cp welcome.jar com.imooc.jardemo1.Welcome		//Work too
``

## 多个jar之间存在调用关系
```
////Create shared library
//cd UseJarZhiHu\jardemo1\src
javac com/imooc/jardemo1/impl/Teacher.java -d target2/
cd target2
jar -cvf teacher.jar *
copy teacher.jar ..\..\..\jardemo2\lib\


//cd sample\UseJarZhiHu\jardemo2\src
javac -cp ../lib/teacher.jar com/imooc/jardemo2/Welcome.java -d target
cd target
//!!!! ";." !!!!必须包含所有的jar
java -cp ../../lib/teacher.jar;.  com.imooc.jardemo2.Welcome
java -cp ../../lib/teacher.jar;.  com.imooc.jardemo2.Welcome

////在target里打jar包
md META-INF
copy ..\..\..\jardemo1\src\META-INF\MANIFEST.MF .\META-INF\
//modify MANIFEST.MF, "jardemo2"
jar -cvfm welcome.jar META-INF/MANIFEST.MF *
//!!!! must include myself: welcome.jar, ;;;; 必须包含所有的!!!!
java -cp welcome.jar;../../lib/teacher.jar com.imooc.jardemo2.Welcome
//Add "Main-Class"	????
java -cp welcome.jar;../../lib/teacher.jar
//上面是库和自己的代码独立, 分别打包

////Class-Path, 把库和自己的代码打成一个包???
//modify MANIFEST.MF, "Class-Path"
jar -cvfm welcome.jar META-INF/MANIFEST.MF *
java -jar welcome.jar	//????

## checkout the whole Git on windows
```
