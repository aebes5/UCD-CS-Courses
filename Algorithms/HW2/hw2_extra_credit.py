from flask import Flask, render_template_string
import numpy as np
import math

app = Flask(__name__)

times = [10 ** 6, 6 * (10 ** 7), 3.6 * (10 ** 8), 8.64 * (10 ** 10), 2.592 * (10 ** 12), 3.1536 * (10 ** 13), 3.1536 * (10 ** 15)] # converted to microseconds

def logCalculator():
    return [f"2**{time}" for time in times]

def squareRoot():
    return [time ** 2 for time in times]

def n():
    return times

def n_log_n():

    arr = []

    for time in times: #trial and error

        solved = False
        lower_bound = 0
        upper_bound = time

        while not solved:
            i = (lower_bound + upper_bound) / 2

            if (abs(i * math.log2(i) - time) / time) < 0.0001:

                solved = True  # within .01% accuracy

            elif i * math.log2(i) < time:

                lower_bound = i

            else:

                upper_bound = i

        arr.append(i)

    return arr

    
    return arr

def squared():
    return [np.power(time, (1/2)) for time in times]

def cubed():
    return [np.power(time, (1/3)) for time in times]

def two_n(): #trial and error

    arr = []

    for time in times:

        i = 1

        while(2**i < time):
            i += 1

        arr.append(i - 1)

    
    return arr

def factorial(): #trial and error
    
    arr = []


    for time in times:

        i = 1
        count = 2

        while(i < time):
            
            i = i * count
            print(i)
            count+=1

        arr.append(count - 2)

    
    return arr


@app.route('/')
def index(): # stored values

    lg_n_values = logCalculator()
    sqrt_values = squareRoot()
    n_values = n()
    n_log_n_values = n_log_n()
    n_sqrt_values = squared()
    n_cubed_values = cubed()
    two_n_values = two_n()
    factorial_values = factorial()

# html code
    html_content = """
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Two-Way Table</title>
  <style>
    table {
      border-collapse: collapse;
      width: 50%;
    }

    th, td {
      border: 1px solid #dddddd;
      text-align: left;
      padding: 8px;
    }

    th {
      background-color: #f2f2f2;
    }
  </style>
</head>
<body>

  <h2>Comparing Running Times</h2>

  <table>
    <tr>
      <th></th>
      <th>1 second</th>
      <th>1 minute</th>
      <th>1 hour</th>
      <th>1 day</th>
      <th>1 month</th>
      <th>1 year</th>
      <th>1 century</th>
    </tr>
    <tr>
      <th>lg n</th>
      {% for value in lg_n_values %}
        <td>{{ (value) }}</td>
      {% endfor %}
    </tr>
    <tr>
      <th>n<sup>1/2</sup></th>
      {% for value in sqrt_values %}
        <td>{{ (value) }}</td>
      {% endfor %}
    </tr>
    <tr>
      <th>n</th>
      {% for value in n_values %}
        <td>{{ (value) }}</td>
      {% endfor %}
    </tr>
    <tr>
      <th>n lg n</th>
      {% for value in n_log_n_values %}
        <td>{{ (value) }}</td>
      {% endfor %}
    </tr>
    <tr>
      <th>n<sup>2</sup></th>
      {% for value in n_sqrt_values %}
        <td>{{ (value) }}</td>
      {% endfor %}
    </tr>
    <tr>
      <th>n<sup>3</sup></th>
      {% for value in n_cubed_values %}
        <td>{{ (value) }}</td>
      {% endfor %}
    </tr>
    <tr>
      <th>2<sup>n</sup></th>
      {% for value in two_n_values %}
        <td>{{ (value) }}</td>
      {% endfor %}
    </tr>
    <tr>
      <th>n!</th>
      {% for value in factorial_values %}
        <td>{{ (value) }}</td>
      {% endfor %}
    </tr>
  </table>

</body>
</html>
    """

    # render document
    return render_template_string(html_content, lg_n_values=lg_n_values, sqrt_values=sqrt_values,
                                  n_values=n_values, n_log_n_values=n_log_n_values, n_sqrt_values=n_sqrt_values, 
                                  n_cubed_values=n_cubed_values, two_n_values=two_n_values, factorial_values=factorial_values)

if __name__ == '__main__':
    app.run(debug=True)
