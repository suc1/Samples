package com.appficial;

public class Student extends Person{
    protected int studentId;

    public Student() {
        super();
        studentId = 0;
    }

    public Student(String name, int age, int studentId) {
        super(name, age);
        this.studentId = studentId;
    }

    public void Print() {
        System.out.printf("Student"); 
    }
}
