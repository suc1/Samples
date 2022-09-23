# sample
```
////1.Create jar
//cd sample\UseJar\JarLibrary\src
javac com/appficial/Student.java -d target

cd target
jar -cvf student.jar *
copy student.jar ..\..\..\JavaApp\lib\

//cd sample\UseJar\JavaApp\src>
////demo.java use "System.out.printf"
javac -cp ../lib/student.jar com/softgold/demo.java -d target
cd target
java com/softgold/demo
java com.softgold.demo

////demo.java use "Student"
javac -cp ../lib/student.jar com/softgold/demo.java -d target
cd target
java -cp ../../lib/student.jar;. com.softgold.demo
//But fail in vscode terminical

//Main-Class & Class-Path ignore????
jar -cvfm demo.jar META-INF/MANIFEST.MF *
java -cp demo.jar;../../lib/student.jar com.softgold.demo
```
