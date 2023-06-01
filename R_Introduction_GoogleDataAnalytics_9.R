library("ggplot2")
library("palmerpenguins")

ggplot(data = penguins) +
  geom_smooth(aes(x = flipper_length_mm, y = body_mass_g, linetype = species)) +
  geom_jitter(aes(x = flipper_length_mm, y = body_mass_g))

ggplot(data = penguins) +
  geom_jitter(aes(x = flipper_length_mm, y = body_mass_g, color = species)) +
  facet_wrap(~species)

ggplot(data = penguins) +
  geom_jitter(aes(x = flipper_length_mm, y = body_mass_g, color = species)) +
  facet_wrap(sex~species)

ggplot(data = diamonds) +
  geom_bar(mapping = aes(x = cut, fill = clarity))

ggplot(data = diamonds) +
  geom_bar(mapping = aes(x = clarity, fill = clarity)) +
  facet_wrap(~cut)