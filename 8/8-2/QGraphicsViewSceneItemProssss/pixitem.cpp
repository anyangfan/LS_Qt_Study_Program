#include "pixitem.h"

PixItem::PixItem(QPixmap *pixmap)
{
    pix=*pixmap;
}


// 此函数只刷新固定区域，重新实现：返回调整成实际物体所在位置的包含区域
QRectF PixItem::boundingRect() const
{
    return QRectF(-2-pix.width()/2,-2-pix.height()/2,pix.width()+4,pix.height()+4);

}
/*
- `boundingRect()` 函数是一个虚函数，用于返回图形项（Graphics Item）的边界矩形（bounding rectangle）。
- 返回类型是 `QRectF`，即浮点数精度的矩形。
- 在这段代码中，返回的矩形是基于 `pix` 的宽度和高度计算的：
  - `pix.width()` 和 `pix.height()` 是图像 `pix` 的宽度和高度。
  - `-2 - pix.width()/2` 和 `-2 - pix.height()/2` 分别是矩形左上角的 x 和 y 坐标，这种方式可以让图形项的原点（0, 0）位于其几何中心附近，而不是左上角。
  - `pix.width() + 4` 和 `pix.height() + 4` 是矩形的宽度和高度，增加了一些额外空间，以确保图形项的边界不会太靠近图形内容的边缘，这有助于避免绘制时的剪切或未预期的裁剪。

*/
// 绘制操作
void PixItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-pix.width()/2,-pix.height()/2,pix);
}

/*
- `paint()` 函数是一个虚函数，用于实际绘制图形项的内容。
- `painter` 是一个 `QPainter` 对象，用于在图形项上绘制内容。
- `pix` 是一个 `QPixmap` 对象，表示要绘制的图像。
- `painter->drawPixmap()` 函数用于绘制 `pix` 图像：
  - `-pix.width()/2` 和 `-pix.height()/2` 是绘制位置的 x 和 y 坐标。这些坐标使得图像的中心位于原点（0, 0）处，而不是左上角。这种偏移通常用于将图像的中心与图形项的中心对齐。
  - `pix` 是要绘制的 `QPixmap` 对象。
*/
 

/*
这段代码实现了一个自定义的图形项 `PixItem`，用于在Qt的图形框架中绘制一个图像。
`boundingRect()` 函数定义了图形项的边界矩形，而 `paint()` 函数则实际绘制了图像。通过调整绘制位置和边界矩形，可以控制图形项的位置和外观，使其在场景中正确显示和交互。
*/