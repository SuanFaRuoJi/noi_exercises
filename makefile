CC = gcc
C_STANDARD = -std=c11
OBJECT_FLAG = -c
TARGET = hello

all:
	echo "Please use this make to create and manage problems."

create:
	if test -d $(TARGET); then echo '$(TARGET) already exists!'; exit; fi
	mkdir $(TARGET)
	touch $(TARGET)/makefile
	./.scripts/generate_makefile.sh $(TARGET) > $(TARGET)/makefile
	touch $(TARGET)/$(TARGET).cpp
	./.scripts/generate_cpp.sh $(TARGET) > $(TARGET)/$(TARGET).cpp
	touch $(TARGET)/$(TARGET).h
	./.scripts/generate_header.sh $(TARGET) > $(TARGET)/$(TARGET).h
	touch $(TARGET)/test_data

clean:
	rm -rf $(TARGET)

reset:
	make clean TARGET=$(TARGET)
	make create TARGET=$(TARGET)

