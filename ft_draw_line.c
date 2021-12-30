
typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

int ft_abs(int i)
{
	if (i > 0)
		return (i);
	return (-i);
}

void ft_draw_line(t_data *img, t_point p0, t_point p1, int color)
{
	int dx = ft_abs(p0.x - p1.x);
	int dy = ft_abs(p0.y - p1.y);
	int sx = (p0.x < p1.x) ? 1 : -1;
	int sy = (p0.y < p1.y) ? 1 : -1;
	int err = dx - dy;
	int e2;

	while (1)
	{
		ft_put_pixel(img, p0.x, p0.y, color);
		e2 = 2 * err;
		if (e2 + dy >= 0)
		{
			if (p0.x == p1.x)
				break;
			err -= dy;
			p0.x += sx;
		}
		if (e2 - dy <= 0)
		{
			if (p0.y == p1.y)
				break;
			err += dx;
			p0.y += sy;
		}
	}
}