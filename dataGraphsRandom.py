import plotly.express as px

# List arguments in wide form


series1 = [0, 0.001, 0, 0.001, 0.002, 0.020, 0.032, 0.174, 0.395, 2.872, 4.894, 41.827,  65.425]
series2 = [0, 0, 0, 0, 0.001, 0.01, 0.017, 0.121, 0.22, 1.242, 2.504, 12.713, 28.361]
series3 = [0, 0, 0, 0, 0.002, 0.009, 0.024, 0.125, 0.273, 1.84,  3.045, 19.886, 34.095]
series4 = [0, 0.002, 0.001, 0.006, 0.007, 0.012, 0.024, 0.123, 0.211, 0.987, 1.954, 14.321, 19.185]
series5 = [0, 0, 0, 0.001, 0.002, 0.018, 0.031, 0.191, 0.377, 2.75, 4.768, 32.47, 65.601]
series6 = [0, 0, 0, 0, 0.001, 0.008, 0.021, 0.149, 0.301, 2.117, 4.053, 30.644, 57.474]

fig = px.line(x=['1e1','1e1-1e2','1e2','1e2-1e3', '1e3','1e3-1e4', '1e4','1e4-1e5', '1e5', '1e5-1e6', '1e6', '1e6-1e7', '1e7'], y=[series1, series2, series3, series4, series5, series6])
newnames = {'wide_variable_0':'myIntrosort', 'wide_variable_1': 'c++ IntroSort', 'wide_variable_2' : 'mergeSort', 'wide_variable_3' : 'radixSort(base 256)', 'wide_variable_4': 'heapSort', 'wide_variable_5' : 'shellSort'}
fig.for_each_trace(lambda t: t.update(name = newnames[t.name],
                                      legendgroup = newnames[t.name],
                                      hovertemplate = t.hovertemplate.replace(t.name, newnames[t.name])
                                     )
                  )

fig.update_layout(
    title="Numere luate random",
    xaxis_title="Marimea datelor de intrare",
    yaxis_title="Timpul de rulare(secunde.ms)",
    legend_title="Algoritmi comparati",
    font=dict(
        size=18,
    )
)
fig.show()