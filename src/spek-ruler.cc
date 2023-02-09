#include "spek-ruler.h"
#include "spek.h"

#include <cmath>
#include <QFontMetrics>

SpekRuler::SpekRuler(
    int x, int y, Position pos, QString sample_label,
    int *factors, int min_units, int max_units, double spacing,
    double scale, double offset, formatter_cb formatter)
    :
    x(x), y(y), pos(pos), sample_label(sample_label),
    factors(factors), min_units(min_units), max_units(max_units), spacing(spacing),
    scale(scale), offset(offset), formatter(formatter)
{
}

void SpekRuler::draw(QPainter &dc)
{
    const QFontMetrics ftm(dc.font());
    const int w = QtFontWidth(ftm, sample_label);
    const int h = ftm.height();
    const int len = this->pos == TOP || this->pos == BOTTOM ? w : h;

    // Select the factor to use, we want some space between the labels.
    int factor = 0;
    for (int i = 0; factors[i]; ++i) {
        if (fabs(this->scale * factors[i]) >= this->spacing * len) {
            factor = factors[i];
            break;
        }
    }

    // Draw the ticks.
    this->draw_tick(dc, min_units);
    this->draw_tick(dc, max_units);

    if (factor > 0) {
        for (int tick = min_units + factor; tick < max_units; tick += factor) {
            if (fabs(this->scale * (max_units - tick)) < len * 1.2) {
                break;
            }
            this->draw_tick(dc, tick);
        }
    }
}

void SpekRuler::draw_tick(QPainter &dc, int tick)
{
    constexpr int GAP = 10;
    constexpr int TICK_LEN = 4;

    const QString &label = this->formatter(tick);
    const int value = this->pos == TOP || this->pos == BOTTOM ? tick : this->max_units + this->min_units - tick;
    const double p = this->offset + this->scale * (value - min_units);

    const QFontMetrics ftm(dc.font());
    const int w = QtFontWidth(ftm, sample_label);
    const int h = -ftm.height() / 2;

    if (this->pos == TOP) {
        dc.drawText(this->x + p - w / 2, this->y - GAP - h, label);
    } else if (this->pos == RIGHT){
        dc.drawText(this->x + GAP, this->y + p - h / 2, label);
    } else if (this->pos == BOTTOM) {
        dc.drawText(this->x + p - w / 2, this->y + GAP * 2, label);
    } else if (this->pos == LEFT){
        dc.drawText(this->x - w - GAP, this->y + p - h / 2, label);
    }

    if (this->pos == TOP) {
        dc.drawLine(this->x + p, this->y, this->x + p, this->y - TICK_LEN);
    } else if (this->pos == RIGHT) {
        dc.drawLine(this->x, this->y + p, this->x + TICK_LEN, this->y + p);
    } else if (this->pos == BOTTOM) {
        dc.drawLine(this->x + p, this->y, this->x + p, this->y + TICK_LEN);
    } else if (this->pos == LEFT) {
        dc.drawLine(this->x, this->y + p, this->x - TICK_LEN, this->y + p);
    }
}
