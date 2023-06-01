install.packages("tidyverse")
install.packages("palmerpenguins")
install.packages("ggplot2")

library(tidyverse)
library(palmerpenguins)
library(ggplot2)

data(penguins)
View(penguins)

ggplot(data = penguins) + 
  geom_point(mapping = aes(x = flipper_length_mm, y = body_mass_g, alpha = species), color = "purple")