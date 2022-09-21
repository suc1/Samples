//了解3D世界的黑魔法-纯Java构造一个简单的3D渲染引擎
//https://mp.weixin.qq.com/s/mnUcffuh0nqhuVXvo9eGLw
//javac -encoding UTF-8 Engine3D.java

import java.awt.*;
import java.util.ArrayList;
import java.awt.geom.Path2D;

import javax.swing.*;

// X 坐标表示左右方向的移动
// Y 表示屏幕上的上下移动
// Z 表示深度（因此 Z 轴垂直于您的屏幕）。正 Z 表示“朝向观察者”。

class Vertex {
    double x;
    double y;
    double z;
    Vertex(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

class Triangle {
    Vertex v1;
    Vertex v2;
    Vertex v3;
    Color color;
    Triangle(Vertex v1, Vertex v2, Vertex v3, Color color) {
        this.v1 = v1;
        this.v2 = v2;
        this.v3 = v3;
        this.color = color;
    }
}

class Matrix3 {     //3 * 3
    double[] values;
    Matrix3(double[] values) {
        this.values = values;
    }
    Matrix3 multiply(Matrix3 other) {   // Matrix(3 * 3) * Matrix(3 * 3)
        double[] result = new double[9];
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                for (int i = 0; i < 3; i++) {
                    result[row * 3 + col] +=
                        this.values[row * 3 + i] * other.values[i * 3 + col];
                }
            }
        }
        return new Matrix3(result);
    }
    Vertex transform(Vertex in) {   // (x, y, z) * Matrix(3 * 3)
        return new Vertex(
            in.x * values[0] + in.y * values[3] + in.z * values[6],
            in.x * values[1] + in.y * values[4] + in.z * values[7],
            in.x * values[2] + in.y * values[5] + in.z * values[8]
        );
    }
}

public class Engine3D {
    public static void main(String[] args) {
        JFrame frame = new JFrame();
        Container pane = frame.getContentPane();
        pane.setLayout(new BorderLayout());
       
        Engine3D eng = new Engine3D();

        // panel to display render results
        eng.renderPanel = new JPanel() {
            public void paintComponent(Graphics g) {
                eng.g2 = (Graphics2D) g;
                eng.g2.setColor(Color.BLACK);
                eng.g2.fillRect(0, 0, getWidth(), getHeight());
                
                // rendering magic will happen here
                
                //**构造目标三维图形**
                eng.InitTriangle();
                eng.Draw();
            }
        };
        pane.add(eng.renderPanel, BorderLayout.CENTER);
        
        frame.setSize(600, 600);
        frame.setVisible(true);
    }
    
    //func
    private void InitTriangle() {
        tris = new ArrayList<Triangle>();
        tris.add(new Triangle(new Vertex(100, 100, 100),
                      new Vertex(-100, -100, 100),
                      new Vertex(-100, 100, -100),
                      Color.WHITE));
        tris.add(new Triangle(new Vertex(100, 100, 100),
                      new Vertex(-100, -100, 100),
                      new Vertex(100, -100, -100),
                      Color.RED));
        tris.add(new Triangle(new Vertex(-100, 100, -100),
                      new Vertex(100, -100, -100),
                      new Vertex(100, 100, 100),
                      Color.GREEN));
        tris.add(new Triangle(new Vertex(-100, 100, -100),
                      new Vertex(100, -100, -100),
                      new Vertex(-100, -100, 100),
                      Color.BLUE));
    }

    private void Draw() {
        // 生成的形状以原点 (0, 0, 0) 为中心，稍后我们将围绕该点进行旋转。
        g2.translate(renderPanel.getWidth() / 2, renderPanel.getHeight() / 2);
        g2.setColor(Color.WHITE);
        for (Triangle t : tris) {
            Path2D path = new Path2D.Double();
            path.moveTo(t.v1.x, t.v1.y);
            path.lineTo(t.v2.x, t.v2.y);
            path.lineTo(t.v3.x, t.v3.y);
            path.closePath();
            g2.draw(path);
        }
    }

    //**旋转: 用鼠标拖曳**
    private void AddDragDraw() {
        renderPanel.addMouseMotionListener(new MouseMotionListener() {
            @Override
            public void mouseDragged(MouseEvent e) {
                double yi = 180.0 / renderPanel.getHeight();
                double xi = 180.0 / renderPanel.getWidth();
                x[0] = (int) (e.getX() * xi);
                y[0] = -(int) (e.getY() * yi);
                renderPanel.repaint();
            }

            @Override
            public void mouseMoved(MouseEvent e) {

            }
        });
    }
    private void DragDraw() {
        // 生成的形状以原点 (0, 0, 0) 为中心，稍后我们将围绕该点进行旋转。
        g2.translate(renderPanel.getWidth() / 2, renderPanel.getHeight() / 2);
        g2.setColor(Color.WHITE);
        for (Triangle t : tris) {
            Path2D path = new Path2D.Double();
            path.moveTo(t.v1.x, t.v1.y);
            path.lineTo(t.v2.x, t.v2.y);
            path.lineTo(t.v3.x, t.v3.y);
            path.closePath();
            g2.draw(path);
        }
    }
    //Data
    private java.util.List<Triangle> tris; 
    private Graphics2D g2;
    private JPanel renderPanel;
}

