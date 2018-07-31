using OxyPlot;
using System.Collections.Generic;
using OxyPlot.Series;

namespace ZetLabGUI
{
    public class GraphModel
    {

        List<DataPoint> points;
        public PlotModel Model { get; private set; }
        public GraphModel(string name="")
        {

            Model = new PlotModel();
            Model.Title = name;
           
            LineSeries series = new LineSeries();
            series.LineStyle = LineStyle.Solid;
            Model.Series.Add(series);
            points = series.Points;
        }

        public void Update(IEnumerable<DataPoint> points)
        {
            lock (Model.SyncRoot)
            {
                this.points.Clear();
                this.points.AddRange(points);

            }

            Model.PlotView.InvalidatePlot(true);

        }
    }
}
