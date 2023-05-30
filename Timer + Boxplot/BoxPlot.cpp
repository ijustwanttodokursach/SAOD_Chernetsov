// BoxPlot.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class BoxPlot {
public:
    static double min(std::vector<double> v);
    static double lq(std::vector<double> v);
    static double median(std::vector<double> v);
    static double mean(std::vector<double> v);
    static double stddev(std::vector<double> v);
    static double uq(std::vector<double> v);
    static double max(std::vector<double> v);
    static void out(std::vector<double> v);

};

double BoxPlot::min( std::vector<double> v) {
    std::sort(v.begin(), v.end());
    double q1 = BoxPlot::lq(v);
    double q3 = BoxPlot::uq(v);
    double iqr = q3 - q1;
    double iqrr = q1 - 1.5 * iqr;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= iqrr) {
           return v[i];
        }
    }
    return 0;
}



double BoxPlot::lq( std::vector<double> v) {
    int index = v.size() * 0.25;
    std::nth_element(v.begin(), v.begin() + index, v.end());
    return v[index];
}



double BoxPlot::median(std::vector<double> v) {
    std::sort(v.begin(), v.end());
    if (v.size() == 2) {
        return BoxPlot::mean(v);
    }
    if (v.size() % 2 != 0) {
        return v[v.size() / 2];
    }
    else {
        return (v[(v.size() / 2) - 1] + v[(v.size() / 2)]) / 2.0;
    }
}

double BoxPlot::mean(std::vector<double> v) {
    return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double BoxPlot::stddev(std::vector<double> v) {
    double variance = 0.0;
    for (int i = 0; i < v.size(); i++) {
        variance += pow(v[i] - BoxPlot::mean(v), 2);
    }
    return sqrt(variance / (v.size() - 1));
}

double BoxPlot::uq(std::vector<double> v) {
    int index = v.size() * 0.75;
    std::nth_element(v.begin(), v.begin() + index, v.end());
    return v[index];
}

double BoxPlot::max(std::vector<double> v) {
    std::sort(v.begin(), v.end());
    double q1 = BoxPlot::lq(v);
    double q3 = BoxPlot::uq(v);
    double iqr = q3 - q1;
    double iqrr = q3 + 1.5 * iqr;
    std::vector<double> res;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= iqrr) {
            res.push_back(v[i]);
        }
    }
    return res[res.size() - 1];
}

void BoxPlot::out(std::vector<double> v) {
    double q1 = BoxPlot::lq(v);
    double q3 = BoxPlot::uq(v);
    double iqr = q3 - q1;
    double iqr_max = q3 + 1.5 * iqr;
    double iqr_min = q1 - 1.5 * iqr;
    std::vector<double> res;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= iqr_min || v[i] >= iqr_max) {
            res.push_back(v[i]);
        }
    }

    for (auto i : res) {
        std::cout << i << " ";
    }
    std::cout << "" << std::endl;
}


int main() {
    std::vector<double> x = { 0.0855298042e+00,1.4513241053e+00,1.3237277269e+00,1.0128350258e+00,1.4122089148e+00,6.5826654434e-01,2.0795986652e+00,1.0230206251e+00,1.4231411219e+00,1.1091691256e+00,1.7714337111e+00,1.3986129761e+00,1.0640757084e+00,1.4216910601e+00,1.2402026653e+00 };
    std::cout.precision(2);
    std::cout << std::scientific << "min:    " << BoxPlot::min(x) << std::endl;
    std::cout << std::scientific << "lq:     " << BoxPlot::lq(x) << std::endl;
    std::cout << std::scientific << "median: " << BoxPlot::median(x) << std::endl;
    std::cout << std::scientific << "mean:   " << BoxPlot::mean(x) << std::endl;
    std::cout << std::scientific << "stddev: " << BoxPlot::stddev(x) << std::endl;
    std::cout << std::scientific << "uq:     " << BoxPlot::uq(x) << std::endl;
    std::cout << std::scientific << "max:    " << BoxPlot::max(x) << std::endl;
    std::cout << std::scientific << "out:    ";
    BoxPlot::out(x);

    /*auto outs = BoxPlot::out(x);
    std::cout << "out: "
        for (const auto& it : out)
            std::cout << std::scientific << it << std::endl;
    std::cout << std::endl;*/
}