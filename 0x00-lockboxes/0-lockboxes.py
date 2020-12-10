#!/usr/bin/python3


def canUnlockAll(boxes):

    unlocked_boxes = [0]
    for box in range(len(boxes)):
        for key in boxes[box]:
            if key not in unlocked_boxes and key != box and key < len(boxes):
                unlocked_boxes.append(key)
    if len(unlocked_boxes) == len(boxes):
        return True
    return False
