///
///
///

#ifndef _RacingBrains_Visualizer_
#define _RacingBrains_Visualizer_

#include <stdint.h>

namespace Visualizer
{
	///
	/// @details 32bit ARGB color with 8bits for each channel.
	///
	typedef uint32_t Color;

	///
	/// @details A 3D vertex for the visualizer, though most often, always? will be 2D??
	///
	struct Vertex { float x, y, z; };

	class VisualizerInterface
	{
	public:
		VisualizerInterface(void);
		virtual ~VisualizerInterface(void);
		
	protected:
		///
		/// @details Called to draw some number of triangles by supplying the vertex of each triangle. The vertices will
		///   be wounded with clockwise representing front face.
		///
		/// @param vertices     An array of vertices, 3 for each triangle.
		/// @param vertexCount  How many vertices in the array, should always be a factor of 3.
		/// @param color        The desired output color, see VisualColor for more information on format.
		///
		virtual void DrawTriangles(const Vertex* vertices, const uint32_t& vertexCount, const Color& color);
		
		///
		/// @details Called to draw some number of lines.
		///
		/// @param vertices     An array of vertices, 2 for each line.
		/// @param vertexCount  How many vertices in the array, should always be a factor of 2.
		/// @param color        The desired output color, see VisualColor for more information on format.
		///
		virtual void DrawLines(const Vertex* vertices, const uint32_t& vertexCount, const Color& color);
	};

	class NullVisualizer
	{
	public:
		NullVisualizer(void);
		virtual ~NullVisualizer(void);
	protected:
		virtual void DrawTriangles(const Vertex* vertices, const uint32_t& vertexCount, const Color& color);
		virtual void DrawLines(const Vertex* vertices, const uint32_t& vertexCount, const Color& color);
	};
	
}; /* Visualizer */

#endif _RacingBrains_Visualizer_
