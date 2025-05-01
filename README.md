# Homework - Generic Pointers and Function Pointers in C++

## Description

This project contains the solutions to my homework assignment on the topic of generic pointers (`void*`) and function pointers in the C++ programming language. The code demonstrates various uses of these concepts, as presented in the attached worksheet.

## Project Contents

The project includes the following files:

* **source.cpp** - The C++ source code file containing the solutions to the different exercises.
* **README.md** - This file, providing a general overview of the project.
* **Employee.cpp** - The C++ source code file defining the `Employee` class.
* **מצביע גנרי ומצביעים לפונקציות** - A digital copy of the worksheet.

## Explanations and Main Features

The code demonstrates the following topics:

* **Generic Pointers (`void*`)**: Using pointers that can point to any data type.
* **Function Pointers**: Using pointers to store the addresses of functions and call them through the pointer.
* **Using `qsort`**: Demonstration of sorting an array of `Employee` objects based on different criteria (salary, seniority, and name) using comparison functions passed as arguments to `qsort`. The comparison functions are defined as static functions within the `Employee` class and accept generic pointers (`const void*`).
* **Using `bsearch`**: Demonstration of binary search in a sorted array of `Employee` objects using the `bsearch` function. The appropriate comparison function (by name) is passed as an argument to `bsearch`.
* **`Employee` Class**: Definition of a class representing an employee with name, salary, and seniority fields. The class includes various static comparison functions used for sorting and searching.

## Note

Ensure that a C++ compiler (such as g++) is installed on your system.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

# שיעורי בית - מצביעים גנריים ומצביעים לפונקציות ב-C++

## תיאור

פרויקט זה מכיל את פתרונות שיעורי הבית שלי בנושא מצביעים גנריים (`void*`) ומצביעים לפונקציות בשפת התכנות C++. הקוד מדגים שימושים שונים של מושגים אלה, כפי שהוצגו בדף העבודה המצורף.

## תוכן הפרויקט

הפרויקט כולל את הקבצים הבאים:

* **source.cpp** - קובץ קוד המקור ב-C++ המכיל את הפתרונות לתרגילים השונים.
* **README.md** - קובץ זה, המספק סקירה כללית של הפרויקט.
* **Employee.cpp**- קובץ קוד המקור ב-C++ המגדיר את המחלקה Employee.
* **מצביע גנרי ומצביעים לפונקציות** - עותק דיגיטלי של דף העבודה.

## הסברים ותכונות עיקריות

הקוד מדגים את הנושאים הבאים:

* **מצביעים גנריים (`void*`)**: שימוש במצביעים שיכולים להצביע על כל סוג נתונים.
* **מצביעים לפונקציות**: שימוש במצביעים כדי לאחסן את הכתובות של פונקציות ולהפעיל אותן דרך המצביע.
* **שימוש ב-`qsort`**: הדגמה של מיון מערך של אובייקטים מסוג `Employee` על בסיס קריטריונים שונים (שכר, ותק ושם) באמצעות פונקציות השוואה המועברות כארגומנטים ל-`qsort`. פונקציות ההשוואה מוגדרות כפונקציות סטטיות בתוך המחלקה `Employee` ומקבלות מצביעים גנריים (`const void*`).
* **שימוש ב-`bsearch`**: הדגמה של חיפוש בינארי במערך ממוין של אובייקטים מסוג `Employee` באמצעות הפונקציה `bsearch`. פונקציית ההשוואה המתאימה (לפי שם) מועברת כארגומנט ל-`bsearch`.
* **מחלקה `Employee`**: הגדרה של מחלקה המייצגת עובד עם שדות שם, שכר וותק. המחלקה כוללת פונקציות השוואה סטטיות שונות המשמשות למיון וחיפוש.

 ## הערה
 הגדרה ודא שמותקן במערכת שלך קומפיילר C++ (כגון g++)


