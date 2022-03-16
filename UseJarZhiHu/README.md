# How to use Jar
https://zhuanlan.zhihu.com/p/82320492

## compile
```
//cd UseJarZhiHu\jardemo1\src
//In same package: one class call another class
javac com/imooc/jardemo1/Welcome.java

//no main manifest attribute, in welcome.jar	//MANIFEST.MF
jar -cvfm welcome.jar META-INF/MANIFEST.MF com/imooc/jardemo1/Welcome.class com/imooc/jardemo1/impl/Teacher.class
java -jar welcome.jar
``

## checkout the whole Git on windows
```
