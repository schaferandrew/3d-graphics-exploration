
#pragma once

#include "graphics/GrVector.h"
#include <vector>
#include "graphics/GrTexture.h"

class CMesh
{
public:
	CMesh();
	virtual ~CMesh();
	void CMesh::Draw();
	void SetTexture(CGrTexture * texture) { m_texture = texture; }
private:
	std::vector<CGrVector> m_vertices;
	std::vector<CGrVector> m_normals;
	std::vector<CGrVector> m_tvertices;

	// A triangle vertex description
	struct TV
	{
		int     v;      // Vertex
		int     n;      // Normal
		int     t;      // Texture coordinate
	};
	typedef std::vector<TV> Triangles;
	typedef Triangles::iterator PTV;
	Triangles       m_triangles;
	CGrTexture *m_texture;
public:
	void AddVertex(const CGrVector &v) { m_vertices.push_back(v); }
	void AddNormal(const CGrVector &n) { m_normals.push_back(n); }
	void AddTexCoord(const CGrVector &t) { m_tvertices.push_back(t); }
	void AddTriangleVertex(int v, int n, int t);
	void AddFlatQuad(int a, int b, int c, int d, int n);
	void AddQuad(int a, int b, int c, int d);
	void LoadOBJ(const char *filename);

};

