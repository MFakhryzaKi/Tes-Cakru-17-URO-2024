import cv2 

video = cv2.VideoCapture("object_video.mp4")


if not video.isOpened() :
    exit()

while True:
    ret, frame = video.read()

    if not ret:
        break
    
    resized_frame = cv2.resize(frame, (640, 320))

    gray = cv2.cvtColor(resized_frame, cv2.COLOR_BGR2GRAY)

    edges = cv2.Canny(gray, 50, 150)
    contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    for i, contour in enumerate(contours):
        # area = cv2.contourArea(contour)
        x, y, w, h = cv2.boundingRect(contour)
        # print(f"Contour {i + 1} - Area: {area}, Bounding Box: x={x}, y={y}, w={w}, h={h}")
        cv2.rectangle(resized_frame, (x-3, y-3), (x+w+3, y+h+3), (0, 255, 0), 2)
        if y > 30:
            cv2.putText(resized_frame, 'red ball', (x, y-10), cv2.FONT_HERSHEY_COMPLEX, 0.5, (0, 0, 200), 2)
        else:
            cv2.putText(resized_frame, 'red ball', (x, y+h+20), cv2.FONT_HERSHEY_COMPLEX, 0.5, (0, 0, 200), 2)
    cv2.imshow("Video", resized_frame)
    
    
    k = cv2.waitKey(10)
    if k % 256 == 27:
        break

video.release()

cv2.destroyAllWindows()



