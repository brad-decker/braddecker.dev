import { useEffect, useState } from 'react';

interface ScrollPointOptions {
  once?: boolean;
}
export function useScrollPoint(options: ScrollPointOptions): [boolean, (element: HTMLElement) => void] {
  const [target, setTarget] = useState<HTMLElement | null>(null);
  const [trigger, setTrigger] = useState(false);
  const { once = true } = options;

  useEffect(() => {
    function handleScroll() {
      if (target) {
        const point = target.getBoundingClientRect().top;
        const height = window.innerHeight;
        if (point < height - 200) setTrigger(true);
        else if (trigger && !once && point > height) setTrigger(false);
      }
    }
    setTimeout(handleScroll, 500);
    window.addEventListener('scroll', handleScroll);
    return () => window.removeEventListener('scroll', handleScroll);
  }, [target, once]);
  return [trigger, setTarget];
}
