const double EPS = 1e-9; 
template<typename T>
bool point_in_polygon( Point<T> point, vector<Point<T>> polygon) {
	int num_vertices = polygon.size();
	T x = point.x, y = point.y;
	bool inside = false;
	Point<T> p1 = polygon[0], p2; // p1 is the first vertex
	for (int i = 1; i <= num_vertices; i++) {
		p2 = polygon[i % num_vertices]; // next vertex

        if (abs((p2.y - p1.y) * (x - p1.x) - (p2.x - p1.x) * (y - p1.y)) < EPS && 
            (x - p1.x) * (x - p2.x) <= 0 && (y - p1.y) * (y - p2.y) <= 0) {
            return true; // point is on the boundary 
        }

		if (y > min(p1.y, p2.y)) { 
			if (y <= max(p1.y, p2.y)) {
                if (p1.x == p2.x) { 
                    if (x <= p1.x) { 
                        inside = !inside;
                    }
                } else if (x <= max(p1.x, p2.x) && x <= (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x) { 
                        inside = !inside;
                } 
            }
        }
		p1 = p2;
	}
    return inside;
}
