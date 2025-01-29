#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Window {
    bool is_closed;
    int x, y, w, h;

    Window(int a_x, int a_y, int a_w, int a_h) { x = a_x; y = a_y; w = a_w; h = a_h; is_closed = false; }

    int lx() const { return x + w - 1; }
    int ly() const { return y + h - 1; }

    bool contains_coord(int a_x, int a_y) const { return !is_closed && a_x >= x && a_x <= lx() && a_y >= y && a_y <= ly(); }
    bool does_overlap(const Window &window) const { return !is_closed && !(x > window.lx() || window.x > lx() || y > window.ly() || window.y > ly()); }

    void print() const { if (!is_closed) cout << x << " " << y << " " << w << " " << h << endl; }
};

int x_max, y_max;
vector<Window> windows;

int get_window_index_from_coord(int a_x, int a_y) {
    for (int i = 0; i < windows.size(); i++) if (windows[i].contains_coord(a_x, a_y)) return i;
    return -1;
}

int get_closest_index(int my_index, const Window &movement_space, string type) {
    int res_index = -1, min_difference = INT_MAX;

    for (int i = 0; i < windows.size(); i++) if (i != my_index && windows[i].does_overlap(movement_space)) {
        if (type == "left" && windows[my_index].x - windows[i].lx() < min_difference) {
            min_difference = windows[my_index].x - windows[i].lx();
            res_index = i;
        } else if (type == "right" && windows[i].x - windows[my_index].lx() < min_difference) {
            min_difference = windows[i].x - windows[my_index].lx();
            res_index = i;
        } else if (type == "up" && windows[my_index].y - windows[i].ly() < min_difference) {
            min_difference = windows[my_index].y - windows[i].ly();
            res_index = i;
        } else if (type == "down" && windows[i].y - windows[my_index].ly() < min_difference) {
            min_difference = windows[i].y - windows[my_index].ly();
            res_index = i;
        }
    }

    return res_index;
}

void move_left(int i, int dx) {
    Window &selected_window = windows[i];

    int target_x_pos = selected_window.x - dx;
    if (target_x_pos < 0) target_x_pos = 0;
    if (target_x_pos >= selected_window.x) return;

    Window movement_space(target_x_pos, selected_window.y, selected_window.x - target_x_pos, selected_window.h);

    int old_closest_index = -1, new_closest_index = get_closest_index(i, movement_space, "left");
    while (old_closest_index != new_closest_index) {
        old_closest_index = new_closest_index;
        move_left(old_closest_index, windows[old_closest_index].x - movement_space.x + windows[old_closest_index].w);
        new_closest_index = get_closest_index(i, movement_space, "left");
        if (new_closest_index == -1) old_closest_index = -1;
    }

    if (old_closest_index == -1) selected_window.x = target_x_pos;
    else selected_window.x = windows[old_closest_index].lx() + 1;
}

void move_right(int i, int dx) {
    Window &selected_window = windows[i];

    int target_x_pos = selected_window.x + dx;
    if (target_x_pos + selected_window.w - 1 >= x_max) target_x_pos = x_max - selected_window.w;
    if (target_x_pos <= selected_window.x) return;

    Window movement_space(selected_window.lx() + 1, selected_window.y, target_x_pos + selected_window.w - selected_window.lx() - 1, selected_window.h);

    int old_closest_index = -1, new_closest_index = get_closest_index(i, movement_space, "right");
    while (old_closest_index != new_closest_index) {
        old_closest_index = new_closest_index;
        move_right(old_closest_index, movement_space.lx() + 1 - windows[old_closest_index].x);
        new_closest_index = get_closest_index(i, movement_space, "right");
        if (new_closest_index == -1) old_closest_index = -1;
    }

    if (old_closest_index == -1) selected_window.x = target_x_pos;
    else selected_window.x = windows[old_closest_index].x - selected_window.w;
}

void move_up(int i, int dy) {
    Window &selected_window = windows[i];

    int target_y_pos = selected_window.y - dy;
    if (target_y_pos < 0) target_y_pos = 0;
    if (target_y_pos >= selected_window.y) return;

    Window movement_space(selected_window.x, target_y_pos, selected_window.w, selected_window.y - target_y_pos);

    int old_closest_index = -1, new_closest_index = get_closest_index(i, movement_space, "up");
    while (old_closest_index != new_closest_index) {
        old_closest_index = new_closest_index;
        move_up(old_closest_index, windows[old_closest_index].y - movement_space.y + windows[old_closest_index].h);
        new_closest_index = get_closest_index(i, movement_space, "up");
        if (new_closest_index == -1) old_closest_index = -1;
    }

    if (old_closest_index == -1) selected_window.y = target_y_pos;
    else selected_window.y = windows[old_closest_index].ly() + 1;
}

void move_down(int i, int dy) {
    Window &selected_window = windows[i];

    int target_y_pos = selected_window.y + dy;
    if (target_y_pos + selected_window.h - 1 >= y_max) target_y_pos = y_max - selected_window.h;
    if (target_y_pos <= selected_window.y) return;

    Window movement_space(selected_window.x, selected_window.ly() + 1, selected_window.w, target_y_pos + selected_window.h - selected_window.ly() - 1);

    int old_closest_index = -1, new_closest_index = get_closest_index(i, movement_space, "down");
    while (old_closest_index != new_closest_index) {
        old_closest_index = new_closest_index;
        move_down(old_closest_index, movement_space.ly() + 1 - windows[old_closest_index].y);
        new_closest_index = get_closest_index(i, movement_space, "down");
        if (new_closest_index == -1) old_closest_index = -1;
    }

    if (old_closest_index == -1) selected_window.y = target_y_pos;
    else selected_window.y = windows[old_closest_index].y - selected_window.h;
}

int main() {
    string command;
    int command_counter = 0;

    cin >> x_max >> y_max;
    while (cin >> command) {
        command_counter++;

        if (command == "OPEN") {
            int x, y, w, h;
            cin >> x >> y >> w >> h;

            Window new_window(x, y, w, h);
            bool can_open = true;
            if (x < 0 || y < 0 || new_window.lx() >= x_max || new_window.ly() >= y_max) can_open = false;
            for (const Window &window : windows) if (window.does_overlap(new_window)) can_open = false;
            if (can_open) windows.push_back(new_window);
            else cout << "Command " << command_counter << ": OPEN - window does not fit" << endl;
        } else if (command == "CLOSE") {
            int x, y;
            cin >> x >> y;

            int i = get_window_index_from_coord(x, y);
            if (i != -1) windows[i].is_closed = true;
            else cout << "Command " << command_counter << ": CLOSE - no window at given position" << endl;
        } else if (command == "RESIZE") {
            int x, y, w, h;
            cin >> x >> y >> w >> h;

            int i = get_window_index_from_coord(x, y);
            if (i != -1) {
                Window &selected_window = windows[i];
                Window resized_window(selected_window.x, selected_window.y, w, h);
                bool can_resize = true;
                selected_window.is_closed = true;
                if (resized_window.lx() >= x_max || resized_window.ly() >= y_max) can_resize = false;
                for (const Window &window : windows) if (window.does_overlap(resized_window)) can_resize = false;
                selected_window.is_closed = false;
                if (can_resize) { selected_window.w = w; selected_window.h = h; }
                else cout << "Command " << command_counter << ": RESIZE - window does not fit" << endl;
            } else cout << "Command " << command_counter << ": RESIZE - no window at given position" << endl;
        } else {
            int x, y, dx, dy;
            cin >> x >> y >> dx >> dy;

            int i = get_window_index_from_coord(x, y);
            if (i != -1) {
                vector<Window> current = windows;
                int o_x = windows[i].x, o_y = windows[i].y;
                if (dx < 0) {
                    move_left(i, -dx);
                    if (windows[i].x - o_x != dx) {
                        int movement = o_x - windows[i].x;
                        windows = current;
                        move_left(i, movement);
                        cout << "Command " << command_counter << ": MOVE - moved " << movement << " instead of " << -dx << endl;
                    }
                } else if (dx > 0) {
                    move_right(i, dx);
                    if (windows[i].x - o_x != dx) {
                        int movement = windows[i].x - o_x;
                        windows = current;
                        move_right(i, movement);
                        cout << "Command " << command_counter << ": MOVE - moved " << movement << " instead of " << dx << endl;
                    }
                } else if (dy < 0) {
                    move_up(i, -dy);
                    if (windows[i].y - o_y != dy) {
                        int movement = o_y - windows[i].y;
                        windows = current;
                        move_up(i, movement);
                        cout << "Command " << command_counter << ": MOVE - moved " << movement << " instead of " << -dy << endl;
                    }
                } else {
                    move_down(i, dy);
                    if (windows[i].y - o_y != dy) {
                        int movement = windows[i].y - o_y;
                        windows = current;
                        move_down(i, movement);
                        cout << "Command " << command_counter << ": MOVE - moved " << movement << " instead of " << dy << endl;
                    }
                }
            } else cout << "Command " << command_counter << ": MOVE - no window at given position" << endl;
        }
    }

    int windows_counter = 0;
    for (const Window &window : windows) if (!window.is_closed) windows_counter++;
    cout << windows_counter << " window(s):" << endl;
    for (const Window &window : windows) window.print();

    return 0;
}
