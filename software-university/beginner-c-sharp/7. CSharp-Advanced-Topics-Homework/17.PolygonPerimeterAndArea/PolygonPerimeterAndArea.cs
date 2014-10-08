using System;
using System.Collections.Generic;
using System.Linq;

class Point
{

    private double _xcoord;
    private double _ycoord;

    public Point()
    {
        _xcoord = 0;
        _ycoord = 0;
    }

    public Point(double x, double y)
    {
        _xcoord = x;
        _ycoord = y;
    }

    public double Xcoord
    {
        get { return _xcoord; }
        set { _xcoord = value; }
    }

    public double Ycoord
    {
        get { return _ycoord; }
        set { _ycoord = value; }
    }

    public double DistanceTo(Point p)
    {
        return Math.Sqrt((p._xcoord - _xcoord) * (p._xcoord - _xcoord) + (p._ycoord - _ycoord) * (p._ycoord - _ycoord));
    }

}

class Polygon
{

    private List<Point> _points;

    public Polygon()
    {
        _points = new List<Point>();
    }

    public Polygon(params Point[] points)
    {
        _points = new List<Point>();
        foreach (Point p in points)
        {
            _points.Add(p);
        }
    }

    public List<Point> Points
    {
        get { return _points; }
        set { _points = value; }
    }

    public double Perimeter()
    {
        double perimeter = 0;
        for (int i = 0; i < _points.Count; i++)
        {
            if(i < _points.Count - 1) perimeter += _points[i].DistanceTo(_points[i + 1]);
            else perimeter += _points[i].DistanceTo(_points[0]);
        }
        return perimeter;
    }

    public double Area()
    {
        double area = 0;
        for(int i=0;i<_points.Count;i++)
        {
            if (i < _points.Count - 1) area += (_points[i].Xcoord * _points[i + 1].Ycoord) - (_points[i].Ycoord * _points[i + 1].Xcoord);
            else area += (_points[i].Xcoord * _points[0].Ycoord) - (_points[i].Ycoord * _points[0].Xcoord);
        }
        return Math.Abs(area / 2);
    }

}

class PolygonPerimeterAndArea
{
    static void Main()
    {
        System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;
        int numberOfPoints = int.Parse(Console.ReadLine());
        Polygon p = new Polygon();
        for (int i = 0; i < numberOfPoints; i++)
        {
            string[] pair = Console.ReadLine().Split();
            p.Points.Add(new Point(double.Parse(pair[0]), double.Parse(pair[1])));
        }
        Console.WriteLine("perimeter = {0:F2}\narea = {1:F2}", p.Perimeter(), p.Area());
    }
}