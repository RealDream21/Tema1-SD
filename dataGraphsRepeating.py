import plotly.express as px

# List arguments in wide form


series1 = [0, 0, 0, 0, 0, 0.008, 0.017, 0.066, 0.135, 1.152, 1.933, 9.306, 18.542]
series2 = [0, 0, 0, 0, 0.001, 0.007, 0.002, 0.073, 0.113, 0.802, 1.376, 9.118, 16.598]
series3 = [0, 0, 0, 0, 0.002, 0.004, 0.015, 0.083, 0.166, 0.397, 0.468, 9.137, 18.775]
series4 = [0, 0, 0, 0, 0.001, 0.005, 0.01, 0.078, 0.139, 1.124, 1.615, 9.249, 20.467]
series5 = [0, 0, 0, 0, 0, 0.002, 0.008, 0.013, 0.077, 0.119, 1.572, 12.306, 16.243]
series6 = [0, 0, 0, 0, 0, 0.009, 0.007, 0.082, 0.111, 0.855, 0.774, 4.605, 9.469]
fig = px.line(x=['1e1','1e1-1e2','1e2','1e2-1e3', '1e3','1e3-1e4', '1e4','1e4-1e5', '1e5', '1e5-1e6', '1e6', '1e6-1e7', '1e7'], y=[series1, series2, series3, series4, series5, series6])
newnames = {'wide_variable_0':'myIntrosort', 'wide_variable_1': 'c++ IntroSort', 'wide_variable_2' : 'mergeSort', 'wide_variable_3' : 'radixSort(base 256)', 'wide_variable_4': 'heapSort', 'wide_variable_5' : 'shellSort'}
fig.for_each_trace(lambda t: t.update(name = newnames[t.name],
                                      legendgroup = newnames[t.name],
                                      hovertemplate = t.hovertemplate.replace(t.name, newnames[t.name])
                                     )
                  )

fig.update_layout(
    title="Numere identice",
    xaxis_title="Marimea datelor de intrare",
    yaxis_title="Timpul de rulare(secunde.ms)",
    legend_title="Algoritmi comparati",
    font=dict(
        size=18,
    )
)
fig.show()