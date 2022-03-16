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

## checkout the whole Git on windows
```
