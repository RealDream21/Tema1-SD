import plotly.express as px

# List arguments in wide form


series1 = [0, 0, 0, 0, 0.001, 0.005, 0.014, 0.084, 0.206, 1.964, 3.461, 31.254, 67.834]
series2 = [0, 0, 0, 0, 0.002, 0.009,  0.014, 0.074, 0.163, 0.875, 1.809, 11.317, 20.191]
series3 = [0, 0.002, 0, 0.001, 0.002, 0.01, 0.022, 0.116, 0.226, 1.396,  2.427, 14.555, 26.13]
series4 = [0, 0, 0, 0.003, 0.004, 0.013, 0.02, 0.098, 0.178, 1.163, 1.684, 8.247, 16.467]
series5 = [0, 0, 0.001, 0, 0.002, 0.017, 0.028, 0.175, 0.35, 2.42, 4.084, 20.611, 48.508]
series6 = [0, 0, 0, 0.001, 0.001, 0.009, 0.013, 0.117, 0.211, 1.725, 3.413, 36.263, 67.237]
fig = px.line(x=['1e1','1e1-1e2','1e2','1e2-1e3', '1e3','1e3-1e4', '1e4','1e4-1e5', '1e5', '1e5-1e6', '1e6', '1e6-1e7', '1e7'], y=[series1, series2, series3, series4, series5, series6])
newnames = {'wide_variable_0':'myIntrosort', 'wide_variable_1': 'c++ IntroSort', 'wide_variable_2' : 'mergeSort', 'wide_variable_3' : 'radixSort(base 256)', 'wide_variable_4': 'heapSort', 'wide_variable_5' : 'shellSort'}
fig.for_each_trace(lambda t: t.update(name = newnames[t.name],
                                      legendgroup = newnames[t.name],
                                      hovertemplate = t.hovertemplate.replace(t.name, newnames[t.name])
                                     )
                  )

fig.update_layout(
    title="Numere apropiate",
    xaxis_title="Marimea datelor de intrare",
    yaxis_title="Timpul de rulare(secunde.ms)",
    legend_title="Algoritmi comparati",
    font=dict(
        size=18,
    )
)
fig.show()