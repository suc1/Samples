# sample
```
////1.Create jar
//cd sample\UseJar\JarLibrary\src
javac com/appficial/Student.java -d target

cd target
jar -cvf student.jar *
copy student.jar ..\..\..\JavaApp\lib\

//cd sample\UseJar\JavaApp\src>
javac -cp ../lib/student.jar com/softgold/demo.java -d target
cd target
java com/softgold/demo
java com.softgold.demo

javac -cp ../lib/student.jar com/softgold/demo.java

jar -cvfm demo.jar META-INF/MANIFEST.MF *

//why fail???
java -jar demo.jar
java -cp ../../lib/student.jar -jar demo.jar
```
