#include "PdfService.hpp"

#include <QPdfWriter>
#include <QPainter>

void PdfService::saveToPdf() {
    QPdfWriter writer("output.pdf");
    QPainter painter(&writer);
    painter.drawText(100, 100, "Pdf created with Qt");
    painter.end();
}
