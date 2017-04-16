///
///
///

#include "visualizer.h"

//--------------------------------------------------------------------------------------------------------------------//

void Visualizer::NullVisualizer::DrawTriangles(const Vertex* vertices, const uint32_t& vertexCount, const Color& color)
{
	((void)vertices);
	((void)vertexCount);
	((void)color);
}

//--------------------------------------------------------------------------------------------------------------------//

void Visualizer::NullVisualizer::DrawLines(const Vertex* vertices, const uint32_t& vertexCount, const Color& color)
{
	((void)vertices);
	((void)vertexCount);
	((void)color);
}

//--------------------------------------------------------------------------------------------------------------------//
