# Makefile cho chương trình quản lý sinh viên
# Sử dụng danh sách liên kết đơn

# Compiler và flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# Tên file executable
TARGET = ung_dung_sinhvien

# Tên file source
SOURCES = test_ung_dung.cpp ung_dung_sinhvien.cpp

# Tên file object
OBJECTS = $(SOURCES:.cpp=.o)

# Mục tiêu chính
all: $(TARGET)

# Tạo executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Compile file .cpp thành .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Chạy chương trình
run: $(TARGET)
	./$(TARGET)

# Chạy trên Windows
run-win: $(TARGET).exe
	$(TARGET).exe

# Tạo executable cho Windows
$(TARGET).exe: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET).exe

# Clean up
clean:
	rm -f $(OBJECTS) $(TARGET) $(TARGET).exe

# Help
help:
	@echo "Cac lenh co the su dung:"
	@echo "  make          - Compile chuong trinh"
	@echo "  make run      - Compile va chay chuong trinh (Linux/Mac)"
	@echo "  make run-win  - Compile va chay chuong trinh (Windows)"
	@echo "  make clean    - Xoa cac file object va executable"
	@echo "  make help     - Hien thi help"

.PHONY: all run run-win clean help

