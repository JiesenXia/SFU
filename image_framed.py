# Name: Tao Tao
# Date: Nov 16


from PIL import Image


orig_image = Image.open("sfu.jpg")
orig_pixels = orig_image.load()   



output_pixels = Image.new("RGB", orig_image.size)
outer = 20
inner = 10



print("Trace orig_image.size",orig_image.size)
print("Trace orig_image.width",orig_image.width)
print("Trace orig_image.height",orig_image.height)

for x in range(output_pixels.width):
        for y in range(output_pixels.height):
                (r,g,b) = orig_pixels[x,y]
                output_pixels.putpixel((x,y),(r,g,b))
                

for x in range(outer):
        for y in range(output_pixels.height):                                                                             
                output_pixels.putpixel((x, y), (0, 0, 0))

for x in range(output_pixels.width-outer,output_pixels.width):
        for y in range(output_pixels.height):
                output_pixels.putpixel((x, y), (0, 0, 0))

for x in range(output_pixels.width):
        for y in range(outer):                                                                             
                output_pixels.putpixel((x, y), (0, 0, 0))

for x in range(output_pixels.width):
        for y in range(output_pixels.height-outer,output_pixels.height):
                output_pixels.putpixel((x, y), (0, 0, 0))                
                

for x in range(outer,outer+inner):
        for y in range(outer,output_pixels.height-outer):
                output_pixels.putpixel((x, y), (100, 100, 30))
                
for x in range(output_pixels.width-outer-inner,output_pixels.width-outer):
        for y in range(outer,output_pixels.height-outer):
                output_pixels.putpixel((x, y), (100, 100, 30))
                
for x in range(outer,output_pixels.width-outer):
        for y in range(outer,outer+inner):
                output_pixels.putpixel((x, y), (100, 100, 30))
                
for x in range(outer,output_pixels.width-outer):
        for y in range(output_pixels.height-outer-inner,output_pixels.height-outer):
                output_pixels.putpixel((x, y), (100, 100, 30))
            


output_pixels.save("sfu_framed.jpg")



