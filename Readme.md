# Arduino Slider MK3 Framework
## Based PlatformIO Development Branch

**NOTE:** The framework is built in PlatformIO using VSC. So recommended to use it to make changes.

---

### Main code
All main code in the `src` folder in `main.cpp` file.
The `setup` and `loop` functions is in this file. All the libraries includes are also. You can add the global functions, your task's functions to appropriate sections. 

**Before pushing make sure that you can build the project**

---

### Include
All the includes in the `include` folder. 

**NOTE:** DO NOT USE `src` folder. It's for other cases.

- #### _funcs_
The global functions should be in this folder `include/funcs/` and contain the following name and extension `<your_function_name>.h`. To write global functions use C++.
After that don't forget to connect it in `src/main.cpp` in appropriate section. 

- #### _helpers_
The helper files should be in this folder. Sometimes some libraries provide examples with files that you don't have. So you can copy them from PlatformIO Library Manager and add it to `include/helpers` folder. 

Don't forget to connect it in `src/main.cpp`, you can do it when you include library. **As a example**, see `IRremote` include which should have `PinDefinitionsAndMore.h` as an extinsion. 

- #### _tasks_
Here where you can add your task function. The name doesn't matter, you can name your function as you want, **BUT DO NOT FORGET TO REMIND** guys who use your function to use this name.

- #### _structure.h_
The task function must use premade structure which is situated in `include/structure.h` file. **NOTE:** Before changing structure you should ask all the group about it. *DO NOT CHANGE STRUCTURE WITHOUT KNOWLEDGE OF OTHERS*

---

### Last but not least
Feel free to ask questions and do suggestions. And yeah, *try to avoid modifying `platformio.ini` manually, use PlatformIO UI*.

Thats it. 

*Tags:*
Fuck the Fed, Ded inside Fed outside, Fed outside cum inside, ORB, IIOP, GIOP, CORBA, gORB  