Class Point {
	public :
		int GetAbsis() {
			return x;
		}
		void SetAbsis(int x) {
			this.x = x;
		}
		void Move (int dx, int dy) {
			x = x + dx;
			y = y + dy;
		}
		int Kuadran() {
			if (x>0) && (y>0) {
				return 1;
			}
			else if (x<0) && (y>0) {
				return 2;
			}
			else if (x<0) && (y<0) {
				return 3;
			}
			else if (x>0) && (y<0) {
				return 4;
			}
		}
	
		Point HasilPindah (int dx, int dy) {
			Point P(x,y);
			P.Move (dx, dy);
			return P;
		}
	
	private :
		int x;
		int y;
}
