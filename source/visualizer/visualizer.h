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

	///
	/// @details Provides the interface required to render triangles and lines to keep the rendering details hidden.
	///
	class VisualizerInterface
	{
	public:
		VisualizerInterface(void);
		virtual ~VisualizerInterface(void);

		///
		/// @note This may or may not be how this is done, may even separate into a different object.
		///
		void DrawBox(const float x, const float y, const float width, const float height, const Color& color = 0xFFFFFFFF);

		///
		/// @note This may or may not be how this is done, may even separate into a different object.
		///
		void DrawLine(const float x1, const float y1, const float x2, const float y2, const Color& color = 0xFFFFFFFF);

	protected:
		///
		/// @details Called to draw some number of triangles by supplying the vertex of each triangle. The vertices will
		///   be wounded with clockwise representing front face.
		///
		/// @param vertices     An array of vertices, 3 for each triangle.
		/// @param vertexCount  How many vertices in the array, should always be a factor of 3.
		/// @param color        The desired output color, see VisualColor for more information on format.
		///
		virtual void DrawTriangles(const Vertex* vertices, const uint32_t& vertexCount, const Color& color) = 0;
		
		///
		/// @details Called to draw some number of lines.
		///
		/// @param vertices     An array of vertices, 2 for each line.
		/// @param vertexCount  How many vertices in the array, should always be a factor of 2.
		/// @param color        The desired output color, see VisualColor for more information on format.
		///
		virtual void DrawLines(const Vertex* vertices, const uint32_t& vertexCount, const Color& color) = 0;
	};

	///
	/// @details A visualizer that does nothing, literally no visuals.
	///
	class NullVisualizer : public VisualizerInterface
	{
	public:
		NullVisualizer(void);
		virtual ~NullVisualizer(void);
	protected:
		virtual void DrawTriangles(const Vertex* vertices, const uint32_t& vertexCount, const Color& color);
		virtual void DrawLines(const Vertex* vertices, const uint32_t& vertexCount, const Color& color);
	};

	///
	/// @details A specific visualizer for TurtleBrains framework, note that although the visualizer takes in 3D vertex
	///   information, TurtleBrains is specifically 2D so Z is completely ignored.
	///
	class TurtleBrainsVisualizer : public VisualizerInterface
	{
	public:
		TurtleBrainsVisualizer(void);
		~TurtleBrainsVisualizer(void);
	protected:
		virtual void DrawTriangles(const Vertex* vertices, const uint32_t& vertexCount, const Color& color);
		virtual void DrawLines(const Vertex* vertices, const uint32_t& vertexCount, const Color& color);
	};

}; /* Visualizer */

#endif /* _RacingBrains_Visualizer_ */
