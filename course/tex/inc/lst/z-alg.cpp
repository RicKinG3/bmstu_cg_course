
void Drawer::zBufForModel(vector<Polygon> &polygons, vector<Vertex> &vertices,
                          Eigen::Matrix4f &trans_mtr, size_t color, Platform *scene, size_t buf_w,
                          size_t buf_h)
{
    /* ... */
    for (size_t cur_polygon = 0; cur_polygon < polygons.size(); cur_polygon++)
    {
        Eigen::MatrixXf cord_vec(3, 4);
        vector<size_t> cur_point = facets.at(cur_polygon).getUsedVertices();
        for (int i = 0; i < 3; i++)
        {
            dotsArr[i] = vertices.at(cur_point.at(i)).getPosition();
            cord_vec.row(i)
                << dotsArr[i].getXCoord(),
                dotsArr[i].getYCoord(), dotsArr[i].getZCoord(), 1;
        }
        cord_vec *= dottrans_mtr;
        /* ... */
        for (int cur_y = (y1 < 0) ? 0 : y1;
             cur_y < ((y2 >= (int)buf_h) ? (int)buf_h - 1 : y2); cur_y++)
        {
            double a_inc = 0;
            if (y1 != y2)
                a_inc = (double)(cur_y - y1) / (y2 - y1);
            double b_inc = 0;
            if (y1 != y3)
                b_inc = (double)(cur_y - y1) / (y3 - y1);
            int x_a = round(x1 + (x2 - x1) * a_inc);
            int x_b = round(x1 + (x3 - x1) * b_inc);
            double z_a = z1 + (z2 - z1) * a_inc;
            double z_b = z1 + (z3 - z1) * b_inc;
            /* ... */
            for (int cur_x = x_a; cur_x <= x_b; cur_x++)
            {
                double curZ = z_a + (z_b - z_a) * (cur_x - x_a) / (x_b - x_a);
                if (curZ >= depthBuffer.at(cur_x).at(cur_y))
                {
                    short visible = 0;
                    for (size_t i = 0; i < scene->getLightNum() && !visible; i++)
                    {
                        /* ... */
                        if (x < (int)shadowMap->size() && x >= 0 &&
                            y < (int)shadowMap->at(0).size() && y >= 0 &&
                            fabs(shadowMap->at(x).at(y) - newCoordinates(0, 2)) < 2)
                            visible = 1;
                    }
                    // Обновляем буфер глубины текущим значением z.
                    depthBuffer.at(cur_x).at(cur_y) = curZ;
                    if (scene->getLightNum())
                        // Если пиксель видим, обновляем буфер кадра соответствующим цветом и признаком видимости.
                        frameBuffer.at(cur_x).at(cur_y) = color + visible;
                    else
                        frameBuffer.at(cur_x).at(cur_y) = color + 1;
                }
            }
        }
        // Аналогичные операции выполняются для следующей части полигона (от y2 до y3)
    }
}