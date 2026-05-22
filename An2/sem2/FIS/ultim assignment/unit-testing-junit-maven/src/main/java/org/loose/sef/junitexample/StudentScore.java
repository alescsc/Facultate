package org.loose.sef.junitexample;

public class StudentScore {
    private String studentName;
    private int score;

    public StudentScore(String studentName, int score) {
        this.studentName = studentName;
        this.score = score;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }

    public String getStudentName() {
        return studentName;
    }

    public void setStudentName(String studentName) {
        this.studentName = studentName;
    }
}