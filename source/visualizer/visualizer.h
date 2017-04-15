///
///
///

#ifndef _RacingBrains_Visualizer_
#define _RacingBrains_Visualizer_

namespace Visualizer
{
	class VisualizerInterface
	{
	public:
		VisualizerInterface(void);
		~VisualizerInterface(void);
		
	protected:
		///
		/// @details Called to draw some number of triangles by supplying the vertex of each triangle. The vertices will
		///   be wounded with clockwise representing front face.
		///
		/// @param vertices     An array of vertices, 3 for each triangle.
		/// @param vertexCount  How many vertices in the array, should always be a factor of 3.
		/// @param color        The desired output color, see VisualColor for more information on format.
		///
		virtual void DrawTriangles(const Vertex* vertices, const size_t& vertexCount, const VisualColor& color);
		
		///
		/// @details Called to draw some number of lines.
		///
		/// @param vertices     An array of vertices, 2 for each line.
		/// @param vertexCount  How many vertices in the array, should always be a factor of 2.
		/// @param color        The desired output color, see VisualColor for more information on format.
		///
		virtual void DrawLines(const Vertex* vertices, const size_t& vertexCount, const VisualColor& color);
	};
	
	
}; /* Visualizer */

#endif _RacingBrains_Visualizer_
