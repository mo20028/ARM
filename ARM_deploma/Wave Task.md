

## lossless media

> Assume ( F=10^8 ) and ( t=1)

![shot_1](https://github.com/mo20028/mo20028/assets/123078771/2552bb25-d389-4a03-a4dd-2a4ed7851e85)



>Both reflection and transmission coefficient is pure real as we in lossless media.
>the summation of reflected and transmitted power equal to the input ( incident ) power.




![shot_2](https://github.com/mo20028/mo20028/assets/123078771/3cdd6a48-0fed-4583-9323-8ce01129be28)


>Reflection and Transmission coefficient is indirectly proportional with epsilon for the second media.
>In this case although the Reflection coefficient is decrease but reflected power increase



![image](https://github.com/mo20028/mo20028/assets/123078771/32763641-239c-41d2-9402-32e01095229e)


>Reflection and Transmission coefficient is directly proportional with mue for the second media.
>SWR increase in both case 
>The shape of standing wave not affected with second media but effected by the first media


![image](https://github.com/mo20028/mo20028/assets/123078771/950da952-d218-42d4-818b-7fd6022aebf2)


## lossy media



### dielectric-dielectric
![image](https://github.com/mo20028/mo20028/assets/123078771/2074ec9f-85d0-4352-9cd2-6fc874513b70)


> In this case the refection and transmission coefficient is complex number.
> the big part of the wave power is transmitted.


### dielectric-conductor
![image](https://github.com/mo20028/mo20028/assets/123078771/5daa39aa-3538-47b7-9499-02af1814a824)

>the most of the wave is reflected as the second media is conductor.
>SWR is big number. 


















## source code 

~~~
% the important part of the code

% Get input values from input fields

epsilon_1=(8.854187817*10^(-12)) *(app.epsilon_1EditField.Value);

epsilon_2=(8.854187817*10^(-12)) *(app.epsilon_2EditField.Value);

mue_1=(1.256637061*10^(-6)) *(app.mue_1EditField.Value);

mue_2=(1.256637061*10^(-6)) *(app.mue_2EditField.Value);

sigma_1=app.sigma_1EditField.Value;

sigma_2=app.sigma_2EditField.Value;

P=app.power_inEditField.Value;

Frq=10^8;

%calculate the impadence(eta) for media one

Z1=sqrt((2*pi*Frq*mue_1*i)/(sigma_1+(2*pi*Frq*epsilon_1*i)));

%calculate the impadence(eta) for media two

Z2=sqrt((2*pi*Frq*mue_2*i)/(sigma_2+(2*pi*Frq*epsilon_2*i)));

% calculate reflaction and transmation coffections

re_co=(Z2-Z1)/(Z2+Z1);

tr_co=(2*Z2)/(Z1+Z2);

SWR=(1+abs(re_co))/(1-abs(re_co));

% set reflaction and transmation coffection values

app.reflectioncoefficientEditField_2.Value=num2str(re_co);

app.transmissioncoefficientEditField_2.Value=num2str(tr_co);

app.standingwaveratioEditField_2.Value=num2str(SWR);

% powers

re_power= (abs(re_co))^2*P; %refelction power

tr_power=( 1- (abs(re_co))^2)*P; %transmitted power

% set powers values

app.transmittedpowerEditField.Value=num2str(tr_power);

app.reflectedpowerEditField.Value=num2str(re_power);

% standing wave

gama=sqrt((i*2*pi*Frq*mue_1)*(sigma_1+i*2*pi*Frq*epsilon_1));

beta=imag(gama);

x=linspace(0,10,1000);

st_wave=2*sin(beta*x);

%plot the standing wave

plot(app.UIAxes,x,st_wave);
~~~

