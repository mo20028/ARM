#lesson 
# inline assembly
>why should I used inline assembly?
>to access the core register and modify it if I want

### how to write inline assembly

~~~assembly
__asm volatile(" move R1 ,R2 ");
__asm volatile(" add R1 ,R2 ");
~~~~

### Arm assembly Ins
~~~
LDR destnation register , source address 
STR source register     , destanation address
ADD destnation register , source register_1 ,source register_2
~~~


### load immediate value in R0
~~~
LDR R1, =#0x10002000  // load adderss in R!
LDR R0, [R1]          // R0=add[R1] from the Ram
~~~

### General form for inline assembly
~~~
__asm volatile("asm instruction": output operand : input operand : clobberl ist)
~~~

>each output and input operand is described by a constrain follow by c expression

**syntax**
~~~
	constrain string (c expression)
~~~

**example**
\- move content of c variable to register
~~~
__asm volatile("MOV R0 ,%0": :"r"(var));
//first no output operand 
//%0 indect for the first operand 
~~~
