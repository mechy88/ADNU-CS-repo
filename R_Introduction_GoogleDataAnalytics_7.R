# Hands-On Activity: Using ggplot
install.packages("tidyverse")
install.packages("ggplot2")

library(tidyverse)
library(ggplot2)

hotel_bookings <- read_csv("hotel_bookings.csv")

ggplot(data = hotel_bookings) +
  geom_point(mapping = aes(x = lead_time, y = children))

ggplot(data = hotel_bookings) +
  geom_jitter(mapping = aes(x = stays_in_weekend_nights, y = children))