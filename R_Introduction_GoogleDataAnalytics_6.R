#practice making scatterplots using ggplot2

library(tidyverse)
library(ggplot2)
library(palmerpenguins)
library(readxl)

bookings <- read_excel("agoda.xlsx")

#Transform function is not working as intended, i.e. it's not properly converting the vector column to numeric, thus problems with graphing
#transform(bookings, No_of_night = as.numeric(as.character(No_of_night)), Commission = as.numeric(as.character(Commission)))

# assignment code with converted vector working (converts character to num)
bookings$Commission <- as.numeric(bookings$Commission)
bookings$No_of_night <- as.numeric(bookings$No_of_night)

ggplot(data = bookings) + geom_point(mapping = aes(x = No_of_night, y = Commission))