# Python程式設計

## 第一章: 輸入與輸出 USER INPUTS AND OUTPUTS

### [1.1]輸入:input | Raw_input

python3 圓面積計算:
```
#!/usr/bin/env python
#coding=utf-8

# radius = 25 
# Input(輸入):Prompt the user to enter a radius
radius = eval(input("Enter a number for radius: "))

# Processing(處理):Compute area
area = radius * radius * 3.1415962

# Output(輸出):Display results
print("The area for the circle of radius", radius, "is", area)
```
輸出:
>Enter a number for radius: 12<br>
>The area for the circle of radius 12 is 452.38985279999997

### [1.2]同時指定(Simultaneous Assignment)
```
#!/usr/bin/env python
#coding=utf-8

# Prompt the user to enter three numbers
number1, number2, number3 = eval(input("Enter three numbers separated by commas: "))

# Compute average
average = (number1 + number2 + number3) / 3

# Display result
print("The average of", number1, number2, number3, "is", average)
```
輸出:
>Enter three numbers separated by commas: 55,100,90
>The average of 55 100 90 is 81.66666666666667
