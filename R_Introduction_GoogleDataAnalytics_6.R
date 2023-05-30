#practice making scatterplots using ggplot2

library(tidyverse)
library(ggplot2)
library(palmerpenguins)
library(readxl)

data("penguins")
View(penguins)


ggplot(data = penguins) + geom_point(mapping = aes(x = flipper_length_mm, y = body_mass_g))

bookings <- read_excel("agoda.xlsx")

ggplot(data = bookings) + geom_point(mapping = aes(x = No_of_night, y = Commission))