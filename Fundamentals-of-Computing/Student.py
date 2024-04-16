"""
Student.py
Andrew Ebert
11/17/2022
"""

class Student:

    def __init__(self, name, hours, qpoints):
        self.name = name
        self.hours = float(hours)
        self.qpoints = float(qpoints)

    def getName(self):
        return self.name

    def getHours(self):
        return self.hours

    def getQPoints(self):
        return self.qpoints

    def gpa(self):
        return self.qpoints/self.hours

    def add_grade(self, grade_points, credits):
        self.hours = self.hours + credits
        self.qpoints = self.qpoints + grade_points
