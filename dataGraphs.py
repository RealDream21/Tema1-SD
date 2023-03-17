import plotly.express as px

# List arguments in wide form


series1 = [3, 5, 4, 8,1,1]
series2 = [5, 4, 8, 3,1,1]
series3 = [1,2, 0.3, 4,1,1]
series4 = [100, 200, 300, 400,1,1]
series5 = [1, 2, 3, 4,1,1]
fig = px.line(x=[100, 200, 300, 400, 10, 20], y=[series1, series2, series3, series4, series5])
newnames = {'wide_variable_0':'myIntrosort', 'wide_variable_1': 'c++ IntroSort', 'wide_variable_2' : 'mergeSort', 'wide_variable_3' : 'radixSort', 'wide_variable_4': 'heapSort'}
fig.for_each_trace(lambda t: t.update(name = newnames[t.name],
                                      legendgroup = newnames[t.name],
                                      hovertemplate = t.hovertemplate.replace(t.name, newnames[t.name])
                                     )
                  )

fig.update_layout(
    title="Plot Title",
    xaxis_title="Marimea datelor de intrare",
    yaxis_title="Timpul de rulare(secunde.ms)",
    legend_title="Legend Title",
    font=dict(
        size=18,
    )
)
fig.show()