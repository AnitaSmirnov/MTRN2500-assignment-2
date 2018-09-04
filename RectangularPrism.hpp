
// Rectangular Prism
// Writtem by Anita Smirnov
// 02/09/18

#include "Shape.hpp"

class RectangularPrism : public Shape
{
public:
    RectangularPrism();
    RectangularPrism(double x_, double y_, double z_, double x_length, double y_length, double z_length, double rotation_);
    void draw();
    ~RectangularPrism();
protected:
    double x_l, y_l, z_l;          // lengths
};
