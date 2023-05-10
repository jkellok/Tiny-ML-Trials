import sensor,image,lcd,time
import KPU as kpu

lcd.init(freq=15000000)
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
#sensor.set_vflip(1)
#sensor.run(1)

task = kpu.load(0x300000)
anchor = (1.889, 2.5245, 2.9465, 3.94056, 3.99987, 5.3658, 5.155437, 6.92275, 6.718375, 9.01025) # bound to model
a = kpu.init_yolo2(task, 0.5, 0.3, 5, anchor) # initialize the model

# when probability higher than predefined in kpu.init_yolo2, draw rectangle on face
# print parameters of model to serial terminal (position of box, dimensions, etc.)
# display the image on lcd when face recognized

while(True):
    img = sensor.snapshot()
    code = kpu.run_yolo2(task, img)
    if code:
        for i in code:
            print(i)
            a = img.draw_rectangle(i.rect())
        a = lcd.display(img)
a = kpu.deinit(task)
