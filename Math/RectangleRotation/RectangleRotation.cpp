/*
 * Problem: Rectangle Rotation (4kyu-CodeWars)
 * Links: https://www.codewars.com/kata/5886e082a836a691340000c3
 * Complexity: O(1) Time, O(1) Space
 * 
 * * CORE LOGIC (Trick xoay trục tọa độ 45 độ):
 * 1. Thay vì để nguyên hình chữ nhật bị nghiêng, ta xoay hệ trục tọa độ đi 45 độ.
 * Hệ trục mới (u,v) Trục hoành là u và trục tung là v
 * Từ 2 phương trình đường thẳng f(x,y) ứng với trục hoành(u) và tung(v), ra được công thức tính khoảng cách từ 1 điểm (x,y) đến u và v, tìm được giới hạn của khoảng cách rồi nhân thêm căn 2 để loại bỏ phần thập phân.
 * Tọa độ mới: u = x + y, v = x - y
 * Vì x, y nguyên => u, v cũng phải nguyên.
 *
 * * 2. Giới hạn của u và v trên trục mới:
 * Chiều dài a, khoảng cách từ tâm đến mép vật lý là a/2.
 * Chiếu lên trục mới (đã loại bỏ mẫu số căn 2 để tọa độ khỏi bị lẻ):
 * na = a / sqrt(2)
 * nb = b / sqrt(2)
 * 
 * * 3. Điều kiện chẵn lẻ (Quan trọng nhất):
 * Ta có: u + v = (x + y) + (x - y) = 2x.
 * Vì 2x luôn CHẴN => u và v bắt buộc phải CÙNG TÍNH CHẴN LẺ.
 * Nếu u, v khác tính chẵn lẻ => x bị lẻ (ví dụ 2.5) => Không hợp lệ.
 * 
 * * 4. Công thức tổ hợp:
 * Tổng số điểm nguyên trên lưới là (2*na + 1) * (2*nb + 1).
 * Vì yêu cầu cùng tính chẵn lẻ (như bàn cờ vua trắng/đen), số điểm hợp lệ chiếm một nửa.
 * Công thức chốt: 2 * na * nb + na + nb + (1 nếu na, nb cùng chẵn/lẻ, ngược lại cộng 0).
 */

#include <cmath>

long long rectangle_rotation(int a, int b) {
    int na = a / sqrt(2);
    int nb = b / sqrt(2);
    
    // (nb % 2 == na % 2) kiểm tra xem na và nb có cùng tính chẵn lẻ hay không
    return 2 * na * nb + na + nb + (nb % 2 == na % 2);
}