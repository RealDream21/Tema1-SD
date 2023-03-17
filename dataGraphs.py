import plotly.express as px

# List arguments in wide form


series1 = [0, 0.001, 0.002, 0.004, 0.004, 0.017, 0.045, 0.231, 0.468, 3.863, 6.249, 56.263, 60]
series2 = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
series3 = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
series4 = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
series5 = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
fig = px.line(x=['1e1','1e1-1e2','1e2','1e2-1e3', '1e3','1e3-1e4', '1e4','1e4-1e5', '1e5', '1e5-1e6', '1e6', '1e6-1e7', '1e7'], y=[series1, series2, series3, series4, series5])
newnames = {'wide_variable_0':'myIntrosort', 'wide_variable_1': 'c++ IntroSort', 'wide_variable_2' : 'mergeSort', 'wide_variable_3' : 'radixSort', 'wide_variable_4': 'heapSort'}
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