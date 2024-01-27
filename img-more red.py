##  CMPT 120
##  Instructor: D. Cukierman
##
##  IMAGE PROCESSING
##
##  NESTED FOR LOOPS - useul to porcess all the image pixels!
##  Opening, loading, saving an image file
##  Color coding
##

# import needed libraries  (download i oyur computer pillow)  (pip
from PIL import Image


# Open and Load original (or input) image:
orig_image = Image.open("beach.jpg")
orig_pixels = orig_image.load()   # this is the original image matrix


# Create output canvas (the matrix) to draw in
output_pixels = Image.new("RGB", orig_image.size)


print("Trace orig_image.size",orig_image.size)
print("Trace orig_image.width",orig_image.width)
print("Trace orig_image.height",orig_image.height)



# Generate image (populate the matrix associated to the output file)
for x in range(output_pixels.width):
        for y in range(output_pixels.height):
            (r, g, b) = orig_pixels[x, y]  # original colors
                                           # 0 <= r <= 255

            ### adding more "redness" (up to a maximum, 255)                               
            r = r + 150
            if r > 255:
                r = 255
            output_pixels.putpixel((x, y), (r, g, b))

# save new image
output_pixels.save("moreRed_beach.jpg")

## END PROGRAM

